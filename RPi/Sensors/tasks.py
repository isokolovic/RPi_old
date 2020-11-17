from celery import shared_task
# form models import Widget

@shared_task
def add(x, y):
    return x + y

@shared_task
def mul(x, y):
    return x * y



