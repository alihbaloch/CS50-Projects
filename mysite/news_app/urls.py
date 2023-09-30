from django.urls import path

from . import views

app_name = "news_app"
urlpatterns = [
    # Homepage
    path("", views.index, name="index"),

    # Fetch news by category
    path("fetch_categories/<str:category_name>/", views.categories, name="categories"),

    # Fetch top headlines for US
    path("fetch_top_headlines/", views.top_headlines, name="top_headlines"),

    # Fetch all global popular news with the specified query:"news"
    path("fetch_all_news/<str:query>/", views.all_news, name="all_news"),

    # Fetch all news by user input
    path("search_results/", views.search_results, name="search_results"),

    # Register user
    path("register/", views.register, name="register"),

    # Login user
    path("login_view/", views.login_view, name="login_view"),

    # Logout user
    path("logout_view/", views.logout_view, name= "logout_view"),

    # User's profile
    path("user_profile/", views.user_profile, name="user_profile")
]