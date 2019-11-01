from django.shortcuts import render

# Create your views here.
def return_sensors_homepage(request):
    return render(request, 'home_sensors.html', {})