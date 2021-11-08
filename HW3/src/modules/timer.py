import time


def timer(callback):
    def wrapper():
        start = time.time()
        callback()
        finish = time.time()
        print('\ntime:\t' + str('{:.3f}'.format(finish - start)) + ' sec')

    return wrapper
