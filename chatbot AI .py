import json
import random
with open("intents>json") as f:
    data = json.load(f)
    while True:
        message = input("you:").lower()
        if message == "quit":
            print("bot: bye!")
            break
        respond_found = False
        for intent in data["intent"]:
            for pattern in intent["pattern"]:
                if pattern.lower() in message:
                    print("bot:",random.choice(intent["responses"]))
                    response_found = True
                    break
                if response_found:
                    break
                if not response_found:
                    print("bot:soory, i didn't understand that.")