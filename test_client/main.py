import asyncio
import websockets

async def interact_with_server():
    uri = "ws://localhost:9001"  # Your WebSocket server URI

    async with websockets.connect(uri) as websocket:
        print("Connected to WebSocket server!")
        print("Type 'help' for more info.")

        # You can use a loop to continuously send and receive messages
        while True:
            # Example: Read a message from the user and send it
            message = input("Send order to server (or 'exit' to quit):")
            if message.lower() == "exit":
                print("Closing connection.")
                break

            if message.lower() == "help":
                print("Available commands:")
                print("1. Type 'exit' to close the connection.")
                print("2. 'order <symbol> <quantity>'\nSymbols: cake, brownie")
                continue

            if "order" in message.lower():
                split_message = message.split()
                if len(split_message) != 3:
                    print("Invalid order format. Use 'order <symbol> <quantity>'.")
                    continue
                symbol = split_message[1]
                quantity = split_message[2]
                if symbol not in ["cake", "brownie"]:
                    print("Invalid symbol. Available symbols: cake, brownie.")
                    continue
                if not quantity.isdigit():
                    print("Invalid quantity. Please enter a number.")
                    continue
                # Construct the message to send
                message = f"order {symbol} {quantity}"
                print("Sending order:", message)
                # Send the message to the server
                await websocket.send(message)
            else: 
                print("Invalid command. Type 'help' for more info.")
                continue

            # Wait for the server's response
            response = await websocket.recv()
            print("Order from server:", response)

# Run the async loop
asyncio.run(interact_with_server())
