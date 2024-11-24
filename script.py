# from datasets import load_dataset
# import os
# import codecs

# ds = load_dataset("deepmind/code_contests")

# i=0

# for item in ds['test']:
#     if i >= 100:
#         break
#     if item['source']==2: # codeforces problem fetching
#         rating_folder = str(item['cf_rating'])
#         problem_folder = str(item['name'])
        
#         # Create rating folder if it doesn't exist
#         if not os.path.exists(rating_folder):
#             os.makedirs(rating_folder)
            
#         # Create problem folder inside rating folder
#         problem_path = os.path.join(rating_folder, problem_folder)
#         if not os.path.exists(problem_path):
#             os.makedirs(problem_path)
            
#         # Create description file
#         description_path = os.path.join(problem_path, "description")
#         with codecs.open(description_path, "w", encoding='utf-8') as f:
#             f.write(item['description'])
            
#         # Process test cases data
#         private_test_data = str(item['private_tests']).replace('\\n', '\n').replace("{", "").replace("}", "").replace("[", "").replace("]", "").replace(",", "").replace("' ", "").replace("'", "").replace("'", "").replace(" '", "").replace(" '", "").replace("input: ", "input:").replace("output: ", "output:")
#         private_test_parts = private_test_data.split("output:")

#         generated_test_data = str(item['generated_tests']).replace('\\n', '\n').replace("{", "").replace("}", "").replace("[", "").replace("]", "").replace(",", "").replace("' ", "").replace("'", "").replace("'", "").replace(" '", "").replace(" '", "").replace("input: ", "input:").replace("output: ", "output:")
#         generated_test_parts = generated_test_data.split("output:")
        
#         # Create test cases file
#         test_cases_path = os.path.join(problem_path, "test_cases")
#         with codecs.open(test_cases_path, "w", encoding='utf-8') as f:
#             for part in private_test_parts[:-1]:
#                 if "input:" in part:
#                     f.write(part.replace("input:", "").strip())

#             for part in generated_test_parts[:-1]:
#                 if "input:" in part:
#                     f.write(part.replace("input:", "").strip())
            

#         # Create expected output file
#         expected_output_path = os.path.join(problem_path, "expected_output")
#         with codecs.open(expected_output_path, "w", encoding='utf-8') as f:
#             f.write(private_test_parts[-1].strip() + "\n")
#             f.write(generated_test_parts[-1].strip() + "\n")

            
#         # Create accuracy file
#         accuracy_path = os.path.join(problem_path, "accuracy")
#         with codecs.open(accuracy_path, "w", encoding='utf-8') as f:
#             pass
        
#         # Create chat-gpt code file
#         chat_gpt_code_path = os.path.join(problem_path, "chat-gpt-code")
#         with codecs.open(chat_gpt_code_path, "w", encoding='utf-8') as f:
#             pass
            
#     i+=1

import os
import shutil

def rename_chat_gpt_files(directory):
    for root, dirs, files in os.walk(directory):
        if 'chat-gpt-code' in files:
            old_file = os.path.join(root, 'chat-gpt-code')
            new_file = os.path.join(root, 'chat-gpt-code.cpp')
            
            # Read content from old file
            with open(old_file, 'r') as f:
                content = f.read()
                
            # Write content to new file
            with open(new_file, 'w') as f:
                f.write(content)
                
            # Remove old file
            os.remove(old_file)

# Call the function with the current directory
rename_chat_gpt_files('.')
