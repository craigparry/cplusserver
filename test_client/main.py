import asyncio
import websockets

async def interact_with_server():
    uri = "ws://localhost:9001"  # WebSocket server URI
    
    async with websockets.connect(uri) as websocket:
        # Send a message to the WebSocket server
        await websocket.send("Hello from Python client!")
        
        # Wait for a response from the server
        response = await websocket.recv()
        print(f"Received from server: {response}")

# Start the client interaction
asyncio.get_event_loop().run_until_complete(interact_with_server())
