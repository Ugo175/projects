import json
import random

# Load sentences from a JSON file
def load_json_file(file_path):
    with open(file_path, 'r') as file:
        data = json.load(file)
    return data

# Pick random letters from words whose length is between 1 to 10
def pick(num_words_to_pick):
    # Path to your JSON file
    file_path = 'genrtd_sentences.json'

    # Load the JSON file
    data = load_json_file(file_path)
    
    return random.choice(data[num_words_to_pick])
    
