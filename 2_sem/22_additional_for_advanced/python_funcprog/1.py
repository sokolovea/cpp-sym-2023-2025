#Замыкания
def say_name(name):
    def say_hello():
        print(f'Hello, {name}!')
    return say_hello

f = say_name('Иванов Иван Иванович')
f()

#Декоратор - общий шаблон
def decorator(my_function):
    def wrapper(*args, **kwargs):
        #дополнительный код
        my_function(*args, **kwargs)
        #дополнительный код
    return wrapper

# аннотация @decorator
def my_function():
    return None
    
my_function = decorator(my_function)
my_function()

