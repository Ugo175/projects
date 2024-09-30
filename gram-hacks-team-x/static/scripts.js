identify();

function translate(text, from, to, output) {
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
        resp.text().then(result=>{
            let translated = result["translated"];
            console.log(result)
            output.textCountent = result["translated"];
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

addEventListener("click", (event)=>{
    console.log(event.target.id);
    switch (event.target.id) {
        case "translate":
            translate(write.value, "English", "Spanish", DISPLAY)
            break;

        case "SETTINGS":
            event.preventDefault();
            readSettings();
            location.href = "/game"
            break;
    
        default:
            break;
    }
});