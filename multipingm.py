from pingm import ipping
import os, logging, threading, time

if __name__ == "__main__":
    with open('input2.txt') as file:
        dump = file.read()
        dump = dump.splitlines()

    list = []
    for ip in dump:
        list.append(ip)
    
    thread = []
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")
    
    for index, ip in enumerate(list):
        x = threading.Thread(target=ipping, args=(ip,))
        thread.append(x)
        x.start()
        

    for x in thread:
        x.join()