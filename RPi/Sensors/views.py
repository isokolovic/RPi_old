from django.shortcuts import render
from .models import DHT11_model

# Create your views here.
class SensorsView():
    def DHT11_view(request):
        data = DHT11_model.objects
        # data = 'asdf'
        return render (request, 'DHT11/DHT11.html', {'data': data})
