identify();

function translator(text, from, to, output) {
    let data = {};
    data["text"] = text;
    data["from"] = from;
    data["to"] = to;
    fetch("/translate", {
        headers: {
            "Content-Type": "application/json",
        },
        method: "POST",
        body: jsonStr(data)
    }).then(resp=>{
        resp.json().then(result=>{
            let translated = result["translated"];
            output.textContent = result["translated"];
        })
    }) // .catch(console.log);
}

function generateText() {
    let data = {};
    data["n"] = nWords.value;
    data["to"] = toLang.value;
    fetch("/translateP",{
        headers: {
            "Content-Type": "application/json",
        },
        method: "POST",
        body: jsonStr(data)
    }).then(resp=>{
        resp.json().then(result=>{
            console.log(result);
            translated.textContent = result["translated"];
            generated.textContent = result["text"];
        })
    }) // .catch(console.log);
}

function readSettings() {
    let settings = {};
    settings["from"] = fromLang.value;
    settings["to"] = toLang.value;
    settings["dificulty"] = dificulty.value;
    
    localStorage.langSettings = jsonStr(settings);
    
}

function readAloud() {
    let to = window.to || window.toLang;
    let text = translated.textContent,
    lang = {"French": "fr-FR", "Spanish": "es-ES"}[to.value],
    voices = speechSynthesis.getVoices();

    let voice = voices.filter(voice=>voice.lang==lang)[0];
    let textToSay = new SpeechSynthesisUtterance(text);
    textToSay.voice = voice;
    textToSay.rate = 0.9;
    speechSynthesis.speak(textToSay);
}

function practice() {
    
}

addEventListener("click", (event)=>{
    switch (event.target.id) {
        case "translate":
            console.log(write.value, from.value, to.value, translated);
            translator(write.value, from.value, to.value, translated);
            break;

        case "SETTINGS":
            event.preventDefault();
            readSettings();
            location.href = "/game"
            break;

        case "read":
            event.preventDefault();
            readAloud();
            break;

        case "generate":
            event.preventDefault();
            console.log("hi")
            generateText();
            break;
    
        default:
            break;
    }
});