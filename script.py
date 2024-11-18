from datasets import load_dataset
import os

ds = load_dataset("deepmind/code_contests")

i=0

for item in ds['train']:
    if i >= 100:
        break
    if item['source']==2: # codeforces problem fetching
        rating_folder = str(item['cf_rating'])
        problem_folder = str(item['name'])
        
        # Create rating folder if it doesn't exist
        if not os.path.exists(rating_folder):
            os.makedirs(rating_folder)
            
        # Create problem folder inside rating folder
        problem_path = os.path.join(rating_folder, problem_folder)
        if not os.path.exists(problem_path):
            os.makedirs(problem_path)
            
        # Create description file
        description_path = os.path.join(problem_path, "description")
        with open(description_path, "w") as f:
            f.write(item['description'])
            
        # Create test cases file
        test_cases_path = os.path.join(problem_path, "test_cases")
        with open(test_cases_path, "w") as f:
            f.write(str(item['private_tests']).replace('\\n', '\n').replace("{", "").replace("}", "").replace("[", "").replace("]", "").replace(",", "").replace("' ", "").replace("'", "").replace("'", "").replace(" '", "").replace(" '", "").replace("input: ", "input:").replace("output: ", "output:").replace("input:", "input:\n").replace("output:", "\n\noutput:\n") + "\n")
            # f.write(str(item['generated_tests']).replace('\\n', '\n'))
            
        # Create accuracy file
        accuracy_path = os.path.join(problem_path, "accuracy")
        with open(accuracy_path, "w") as f:
            pass
        
        # Create chat-gpt code file
        chat_gpt_code_path = os.path.join(problem_path, "chat-gpt-code")
        with open(chat_gpt_code_path, "w") as f:
            pass
            
    i+=1

