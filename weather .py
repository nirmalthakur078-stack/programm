

def get_weather(city):
    api_key = "YOUR_API_KEY_HERE"   
    url = f"https://api.openweathermap.org/data/2.5/weather?q={city}&appid={api_key}&units=metric"

    response = requests.get(url)
    data = response.json()

    if data["cod"] == 200:
        print("\n🌦️ Weather Report")
        print("---------------------")
        print(f"City: {data['name']}")
        print(f"Temperature: {data['main']['temp']}°C")
        print(f"Weather: {data['weather'][0]['description']}")
        print(f"Humidity: {data['main']['humidity']}%")
        print(f"Wind Speed: {data['wind']['speed']} m/s")
    else:
        print("\n❌ City not found. Please enter a valid city name.")

def main():
    print("===== Weather App =====")
    city = input("Enter city name: ")
    get_weather(city)

main()

