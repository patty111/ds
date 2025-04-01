import os
import asyncio
import pandas as pd
from dotenv import load_dotenv
import requests

# AI Agent related modules
from autogen_agentchat.agents import AssistantAgent, UserProxyAgent
from autogen_agentchat.conditions import TextMentionTermination
from autogen_agentchat.teams import RoundRobinGroupChat
from autogen_agentchat.messages import TextMessage
from autogen_ext.models.openai import OpenAIChatCompletionClient
from autogen_ext.agents.web_surfer import MultimodalWebSurfer

load_dotenv()

async def process_chunk(chunk, start_idx, total_records, model_client, termination_condition):
    """
    Process a single batch of wine quality data,
    - Let AI analyze the impact of chemical properties on wine quality
    - Use MultimodalWebSurfer to search for international wine standards
    - Integrate AI agent responses and return
    """
    chunk_data = chunk.to_dict(orient='records')
    prompt = (
        f"Processing records {start_idx} to {start_idx + len(chunk) - 1} (total {total_records} records).\n"
        f"Batch data:\n{chunk_data}\n\n"
        "Please analyze based on the following points:\n"
        "1. Analyze the relationship between chemical properties and wine quality scores.\n"
        "2. Calculate quality score distribution and identify factors that most influence wine quality.\n"
        "3. Use MultimodalWebSurfer to search for international wine standards for comparison.\n"
        "4. Provide a comprehensive analysis report and conclusions."
    )
    
    wine_analyzer = AssistantAgent("WineAnalyzerAgent", model_client)
    statistician = AssistantAgent("StatisticianAgent", model_client)
    web_researcher = MultimodalWebSurfer("WebResearchAgent", model_client)
    user_proxy = UserProxyAgent("UserProxyAgent")
    
    team = RoundRobinGroupChat(
        [wine_analyzer, statistician, web_researcher, user_proxy],
        termination_condition=termination_condition
    )
    
    messages = []
    async for event in team.run_stream(task=prompt):
        if isinstance(event, TextMessage):
            print(f"[{event.source}] => {event.content}\n")
            messages.append({
                "batch_start": start_idx,
                "batch_end": start_idx + len(chunk) - 1,
                "source": event.source,
                "content": event.content
            })
    return messages

def get_wine_data():
    """
    Read the wine quality dataset
    """
    try:
        df = pd.read_csv('../data/winequality-red.csv', sep=';')
        return df
    except Exception as e:
        print(f"Error reading wine data: {e}")
        return None

async def main():
    gemini_api_key = os.environ.get("GEMINI_API_KEY")
    if not gemini_api_key:
        print("Please check GEMINI_API_KEY in your .env file.")
        return
    
    model_client = OpenAIChatCompletionClient(
        model="gemini-2.0-flash",
        api_key=gemini_api_key,
    )
    
    termination_condition = TextMentionTermination("exit")
    
    # Read wine quality dataset
    df = get_wine_data()
    if df is None:
        return
        
    chunk_size = 100  # Smaller chunk size since wine dataset is smaller
    chunks = [df[i:i + chunk_size] for i in range(0, len(df), chunk_size)]
    total_records = len(df)
    
    tasks = [
        process_chunk(chunk, idx * chunk_size, total_records, model_client, termination_condition)
        for idx, chunk in enumerate(chunks)
    ]
    
    results = await asyncio.gather(*tasks)
    all_messages = [msg for batch in results for msg in batch]
    
    df_log = pd.DataFrame(all_messages)
    output_file = "wine_quality_analysis_log.csv"
    df_log.to_csv(output_file, index=False, encoding="utf-8-sig")
    print(f"Analysis results have been saved to {output_file}")

if __name__ == '__main__':
    asyncio.run(main())
