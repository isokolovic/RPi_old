from django.db import models
from .DHT11 import DHT11_adafruit as DHT11

# Create your models here.
class DHT11_model(models.Model):    
    temperature_humidity = models.CharField(max_length=100, default= DHT11.temperature_humidity())
    
    def __str__(self):
        return self.temperature_humidity
