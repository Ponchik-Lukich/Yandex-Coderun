import json


def main():
    with open('input.txt', 'r') as f:
        input_txt = f.readlines()
        n, m = map(int, input_txt[0].strip().split())
        users = map(lambda s: s.strip().split(), input_txt[1:n + 1])
        users = [
            dict(
                triggers=s[2:int(s[0]) + 2],
                all=s[2:int(s[0]) + int(s[1]) + 2],
            )
            for s in users
        ]
    req_data = {}
    fields = ['price', 'stock_count']
    subfields = ['title', 'description']
    for req in input_txt[n + 1:]:
        req = json.loads(req.strip())
        req_id = req["offer"]["id"]
        if req_id not in req_data:
            req_data[req_id] = {}
        for key, req_body in req["offer"].items():
            if key == "id":
                continue
            if key in fields:
                req_data[req_id][key] = [req_body, True] if key not in req_data[req_id] or req_body != \
                                                            req_data[req_id][key][0] else [req_body, False]
            elif key == "partner_content":
                for sub_key, sub_req_body in req_body.items():
                    full_key = f"{key}.{sub_key}"
                    req_data[req_id][full_key] = [sub_req_body, True] if full_key not in req_data[
                        req_id] or sub_req_body != req_data[req_id][full_key][0] else [sub_req_body, False]
            else:
                for sub_key, sub_req_body in req_body.items():
                    full_key = f"{key}.{sub_key}"
                    req_data[req_id][full_key] = [sub_req_body, False]
        # print(req_data)
        false_set = set()
        for user in users:
            flag = False
            for field in user["triggers"]:
                if field == "partner_content":
                    for sub_field in subfields:
                        if field + "." + sub_field in req_data[req_id] and req_data[req_id][field + "." + sub_field][1] is True:
                            flag = True
                            break
                if field in req_data[req_id] and req_data[req_id][field][1] is True:
                    flag = True
                    break
            if flag is False:
                continue
            flag = False
            res = {"trace_id": req["trace_id"], "offer": {"id": req_id}}
            for field in user["all"]:
                if field == "partner_content":
                    res["offer"][field] = {}
                    for sub_field in subfields:
                        if field + "." + sub_field in req_data[req_id]:
                            res["offer"][field][sub_field] = req_data[req_id][field + "." + sub_field][0]
                            false_set.add(field + "." + sub_field)
                            flag = True
                    if flag is False:
                        del res["offer"][field]
                if field in req_data[req_id]:
                    res["offer"][field] = req_data[req_id][field][0]
                    false_set.add(field)
            if len(res["offer"]) > 1:
                print(json.dumps(res))
        for field in false_set:
            req_data[req_id][field][1] = False


if __name__ == "__main__":
    main()