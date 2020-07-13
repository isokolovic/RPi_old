from django.shortcuts import render

class HomeView():
    def home(request):
        return render(request, 'home.html')
