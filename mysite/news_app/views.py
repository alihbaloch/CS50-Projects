from django.shortcuts import render, redirect
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from django.contrib import messages
from .forms import RegisterForm
from .models import UserProfile
from .helpers import fetch_top_headlines, fetch_categories, fetch_all_news, fetch_search_results
from .helpers import api_error, user_search_error, no_results_error


def register(request):
    """
    Register view for user registration.

    Handles user registration form submission. If the form is valid,
    a new user account is created, and the user is logged in. If not,
    validation errors are displayed.

    Args:
        request: The HTTP request object.

    Returns:
        HttpResponse: A response containing the registration form.
    """

    if request.method == "POST":
        form = RegisterForm(request.POST)
        if form.is_valid():
            form.save()
            username= form.cleaned_data['username']
            password= form.cleaned_data['password1']
            user = authenticate(username=username, password=password)
            login(request, user)

            UserProfile.objects.create(user=user)
            messages.success(request, ("Registration Successful! You can now log in."))
            return redirect('news_app:login_view')
    else:
        form = RegisterForm()

    return render(request, "users/register.html", {
        "form":form
    })
    

def login_view(request):
    """
    Login view for user authentication.

    Handles user login form submission. If the provided credentials are valid,
    the user is logged in and redirected to their profile page. If not, an error
    message is displayed.

    Args:
        request: The HTTP request object.

    Returns:
        HttpResponse: A response containing the login form.
    """
    
    if request.method == "POST":
        username = request.POST['username']
        password = request.POST['password']
        user = authenticate(username=username, password=password)
        if user is not None:
            login(request, user)
            return redirect('news_app:user_profile')
        else:
            messages.error(request, "Invalid username or password, please try again.")
            return redirect('news_app:login_view')

    return render(request, "users/login.html")
        

def logout_view(request):
    """
    Logout view for user logout.

    Logs out the authenticated user and redirects them to the login page.

    Args:
        request: The HTTP request object.

    Returns:
        HttpResponse: A redirect response to the login view.
    """

    logout(request)
    return redirect('news_app:login_view')


@login_required
def user_profile(request):
    """
    User profile view.

    Displays the user's profile information if they are authenticated.

    Args:
        request: The HTTP request object.

    Returns:
        HttpResponse: A response containing the user's profile page.
    """

    user_profile = UserProfile.objects.get(user=request.user)
    
    return render(request, "users/profile.html", {
        "user_profile": user_profile
    })


#  Renders the Homepage
def index(request):
    """
    Render the homepage.

    Parameters:
    - request: The HTTP request object.
    Returns:

    - Rendered HTML template.
    """

    return render(request, "base/index.html")


def categories(request, category_name):
    """
    Render news articles for a specific category.

    Parameters:
    - request: The HTTP request object.
    - category_name (str): The name of the category.
    Returns:

    - Rendered HTML template with data.
    - In case of an API error, an error message is rendered.

    Data = zip(article_titles, article_images, article_descriptions, article_urls) <-- returning from fetch_categories function.
    """

    data = fetch_categories(category_name)

    if data is None:
       return api_error(request)
    
    return render(request, "news/categories.html", {
        "data":data,
        "category_name":category_name
    })
    

def top_headlines(request):
    """
    Render top headlines for the US.

    Parameters:
    - request: The HTTP request object.
    Returns:

    - Rendered HTML template with top headlines.
    - In case of an API error, an error message is rendered.
    """
    
    data = fetch_top_headlines()

    if data is None:
        return api_error(request)
    
    return render(request, "news/top_headlines.html", {
        "data":data
    })

def all_news(request, query):
    """
    Render global popular news based on query "news".

    Parameters:
    - request: The HTTP request object.
    - query (str): The search query.

    Returns:
    - Rendered HTML template with news articles.
    - In case of an API error, an error message is rendered.
    """

    data = fetch_all_news(query)

    if data is None:
        return api_error(request)
    
    return render(request, "news/all_news.html", {
        "data":data
    })


def search_results(request):
    """
    Render search results based on user input.

    Parameters:
    - request: The HTTP request object.

    Returns:
    - Rendered HTML template with search results.
    - In case of an API error, an error message is rendered.
    - In case of an empty user query, a user search error message is rendered.
    - In case of no search results, a "No Results For" message is rendered.
    """
    
    user_query = request.GET.get("q", "")

    query_result = fetch_search_results(user_query)

    if not user_query:
        return user_search_error(request)
    
    elif query_result is None:
        return api_error(request)
    
    elif all(not item for item in query_result):
        return no_results_error(request, user_query)
    
    return render(request, "news/search_results.html", {
        "query_result":query_result,
        "user_query":user_query
    })
    
