from django.core.management.base import BaseCommand
from news_app.helpers import top_headlines 

class Command(BaseCommand):
    help = 'Run my custom script'

    def handle(self, *args, **kwargs):
        top_headlines()
