import json

from pick import pick
from flask import Flask
from flask import url_for
from flask import render_template
from flask import request
import openai

app = Flask(__name__)

@app.route('/')
def home():
    return render_template("home.html")

@app.route("/practice")
def practice():
    return render_template("practice.html")

@app.route("/settings")
def settings():
    return render_template("settings.html")

@app.route("/game")
def game():
    return render_template("game.html")

@app.route('/translateP', methods=['POST'])
def translate_p():
    if request.method == "POST":
        data = json.loads(request.data)
        text = pick(data["n"])
        print(data["to"])
        translated = translator(text, data["to"])
        result = {
            "text": text,
            "translated": translated
        }
        return result
    return "Failed"



@app.route('/translate', methods=['POST'])
def translate():
    if request.method == 'POST':
        data = json.loads(request.data)
        text = data["text"]
        translated_text = translator(text, data["to"])
        result = {
            "text": text,
            "translated": translated_text
        }
        return json.dumps(result)
    return "BAD REQUEST"


openai.api_key = "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"

def translator(text, target_language):
    messages = [
        {"role": "system", "content": "You are a helpful assistant that translates text."},
        {"role": "user", "content": f"Translate the following text to {target_language}: '{text}'"}
    ]

    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",  # Or "gpt-4" if you're using GPT-4
        messages=messages  # Correct parameter for chat-based models
    )
    
    # Extract the translated text
    translated_text = response['choices'][0]['message']['content'].strip()
    return translated_text



# with app.test_request_context():
#     for route in ("home", "practice", "settings", "game"):
#         print(url_for(route))

# https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtL2I2NDI3NGVjOGVjNzQ1YTZhMWU5ZDFlYzNlMDgxOWE4X0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF8xOWVjY2JmOS1hNDA0LTRlNDAtOGM0ZS1iMjFkMDQwZjFiOTU=
