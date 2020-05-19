import os, logging, threading, time

mutex = threading.Lock()

def ipping (ip):
    #logging.info("Process {} starting".format(os.getpid()))
    mutex.acquire()
    logging.info("Thread {} starting".format(threading.current_thread().ident))
    os.system('nmap -sP {}'.format(ip))
    logging.info("Thread {} done".format(threading.current_thread().ident))
    mutex.release()
    #logging.info("Process {} done".format(os.getpid()))
    

if __name__ == "__main__":
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")
    ip = input('Write IP: ')
    logging.info("Process {} starting".format(os.getpid()))
    x = threading.Thread(target=ipping, args=(ip,))
    x.start()
    x.join()
    logging.info("Process {} done".format(os.getpid()))