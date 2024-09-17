#!/usr/bin/python3
"""
0-count
"""
import requests


def count_words(subreddit, word_list, after=None, wc={}):
    headers = {'User-Agent': 'toto'}
    params = {'limit': 100, 'after': after}
    addr = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    response = requests.get(addr, headers=headers, params=params)

    if response.status_code != 200:
        return

    data = response.json()
    posts = data['data']['children']
    word_list = [word.lower() for word in word_list]
    for post in posts:
        title = post['data']['title'].lower()
        words_in_title = title.split()

        for word in word_list:
            wc[word] = wc.get(word, 0) + words_in_title.count(word)
    after = data['data'].get('after')
    if after:
        count_words(subreddit, word_list, after=after, wc=wc)
    else:
        srt = sorted(wc.items(), key=lambda item: (-item[1], item[0]))
        for word, count in srt:
            if count > 0:
                print(f"{word}: {count}")
    return wc
