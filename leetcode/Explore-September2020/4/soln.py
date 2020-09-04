class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        if(S == ''):
            return []
        str_list = list(S)
        res = []
        letter_index = 0
        while(letter_index < len(str_list)):
            part = list(str_list[letter_index])
            i = letter_index
            while(True):
                print(f"i = {i}, len = {len(part)}")
                if(i >= letter_index + len(part)) :
                    break
                letter = part[i - letter_index]
                sub_list = str_list[letter_index + len(part) : len(str_list)]
                if(letter in sub_list):
                    rep_letter_index = sub_list.index(letter)
                    part += sub_list[0 : rep_letter_index + 1]
                i += 1
            res.append(len(part))
            letter_index = letter_index + len(part)
        return res     
