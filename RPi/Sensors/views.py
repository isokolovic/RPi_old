from django.shortcuts import render
from .models import DHT11_model

# Create your views here.
class SensorsView():
    def sensors_homepage(request):
        return render (request, 'home_sensors.html')
    
    
        #return render (request, 'DHT11/DHT11.html', {'data': data})
        
