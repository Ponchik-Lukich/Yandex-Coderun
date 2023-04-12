import requests
import json

def get_positive_sorted_data(server, port, a, b):
    url = f"{server}:{port}?a={a}&b={b}"
    response = requests.get(url)
    data = json.loads(response.text)
    positive_sorted_data = sorted([x for x in data if x > 0], reverse=True)
    return positive_sorted_data

if __name__ == "__main__":
    server = input()
    port = input()
    a = input()
    b = input()

    result = get_positive_sorted_data(server, port, a, b)
    print("\n".join(map(str, result)))
