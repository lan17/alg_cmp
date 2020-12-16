import re
from dataclasses import dataclass
from typing import List
import re

HGT_REGEX = re.compile('([0-9]+)(in|cm)')
HCL_REGEX = re.compile('^#[0-9a-f]{6}')

def check_num(val:str, low, high):
    try:
        n = int(val)
        return low <= n <= high
    except ValueError:
        return False

@dataclass(frozen=True)
class Field:
    name:str
    value:str

    def is_valid(self):
        if self.name == 'byr':
            return check_num(self.value, 1920, 2002)
        elif self.name == 'iyr':
            return check_num(self.value, 2010, 2020)
        elif self.name == 'eyr':
            return check_num(self.value, 2020, 2030)
        elif self.name == 'hgt':
            m =  HGT_REGEX.match(self.value)
            if not m:
                return False
            num = int(m.group(1))
            if m.group(2) == 'cm':
                return 150 <= num <= 193
            elif m.group(2) == 'in':
                return 59 <= num <= 76
        elif self.name == 'hcl':
            return HCL_REGEX.match(self.value) and len(self.value) == 7
        elif self.name == 'ecl':
            return self.value in ('amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth')
        elif self.name == 'pid':
            return len(self.value) == 9 and self.value.isdecimal()
        return True





def is_valid_passport(passport:List[Field]) -> bool:
    names = {field.name for field in passport}
    is_valid =  len(names) == 8 or (len(names) == 7 and 'cid' not in names)
    print(names, is_valid)
    return is_valid

def is_valid_2(passport:List[Field]) -> bool:
    return is_valid_passport(passport) and all([field.is_valid() for field in passport])



def main():
    with open('day4.in') as file:
        passports = []
        passport = []
        for line in file.readlines():
            if line.strip() == '':
                passports.append(passport)
                passport = []
            else:
                field_strs = line.strip().split(' ')
                for field_str in field_strs:
                    field_parts = field_str.split(':')
                    passport.append(Field(name=field_parts[0], value=field_parts[1]))
        if passport:
            passports.append(passport)
        print(passports)
        print(len([passport for passport in passports if is_valid_passport(passport)]))
        print(len([passport for passport in passports if is_valid_2(passport)]))






if __name__ == '__main__':
    main()