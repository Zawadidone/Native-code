#!/usr/bin/python

import random
import os


def flip_byte(in_bytes):
    i = random.randint(0, len(in_bytes))
    c = chr(random.randint(0, 0xFF))
    return in_bytes[:i]+c+in_bytes[i+1:]

def copy_binary():
    os.system("cp license_2 license_2_fuzz")
    with open("license_2", "rb") as orig_f, open("license_2_fuzz", "wb") as new_f:
        new_f.write(flip_byte(orig_f.read()))

def compare(f1, f2):
    with open(f1) as f1, open(f2) as f2:
        return f1.read == f2.read()

def check_output():
    os.system("./license_2_fuzz AAAA-Z10N-42-OK > fuzz_output")
    return compare("orig_output", "fuzz_output")

def check_gdb():
    os.system("echo disassemble main | gdb license_2_fuz > fuzz_gdb")
    return compare("orig_gdb", "fuzz_gdb")

while True:
    copy_binary()
    if check_output():
        print "Succes"
        os.system("tail fuzz_gdb")

