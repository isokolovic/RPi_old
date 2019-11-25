from django.db import models
from .DHT11 import DHT11_adafruit as DHT11

# Create your models here.
class DHT11_model(models.Model):
    temperature_humidity = DHT11.temperature_humidity()

    def __str__(sellf):
        return self.temperature_humidity