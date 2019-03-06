import requests

url = "https://api.github.com/search/repositories?q=language:python&sort=starts"
r = requests.get(url)
print("Status code:",r.status_code)

response_dict = r.json()
print('Total Count:' + str(response_dict['total_count']))

# 搜索有关仓库的信息
repo_dicts = response_dict['items']
print("Responses returned:",len(repo_dicts))

# 查看第一个仓库
repo_dict =repo_dicts[0]
print("\nKeys:",len(repo_dict))
for key in sorted(repo_dict.keys()):
    print(key)