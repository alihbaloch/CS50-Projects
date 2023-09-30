import requests
from django.shortcuts import render


# API key to fetch news data from NEWSAPI
API_KEY ="a8d520a0f5ae46b080e06b4ab02a2346"


def api_error(request):
    """
    Render an error message for API-related errors.

    Parameters:
    - request (HttpRequest): The HTTP request object.

    Returns:
    - HttpResponse: Rendered HTML template with an error message.
    """

    error_message = "We are unable to fetch news data at this time. Please try again later."
    return render(request, "errors/api_error.html", {
        "error_message": error_message
    })


def user_search_error(request):
    """
    Render an error message for empty user search input.

    Parameters:
    - request (HttpRequest): The HTTP request object.

    Returns:
    - HttpResponse: Rendered HTML template with an error message.
    """

    error_message = "Your search bar is empty. To search for articles, please type something in the search bar"
    return render(request, "errors/user_search_error.html", {
        "error_message":error_message
    })


def no_results_error(request, user_query):
    """
    Render an error message for no search results.

    Parameters:
    - request (HttpRequest): The HTTP request object.
    - user_query (str): The user's search query.

    Returns:
    - HttpResponse: Rendered HTML template with an error message.
    """

    error_message = "No Results For"
    return render(request, "errors/no_search_results.html", {
        "error_message":error_message,
        "user_query":user_query
    })


def fetch_data(endpoint, params):
    """
    Fetch news data from NEWSAPI.

    Parameters:
    - endpoint (str): The API endpoint to fetch data from.
    - params (dict): Parameters to include in the API request.

    Returns:
    - zip: A zipped collection of article titles, images, descriptions, and URLs.
    - None: In case the request is unsuccessful.
    """
    
    url= f"https://newsapi.org/v2/{endpoint}"
    params["apikey"]=API_KEY
   
    response=requests.get(url, params=params)

    if response.status_code == 200:
        news= response.json()
        articles= news.get("articles", [])

        article_titles=[]
        article_images=[]
        article_descriptions=[]
        article_urls=[]
       
        for article in articles:       
            title = article.get("title", "")
            image = article.get("urlToImage", "")
            description = article.get("description", "")
            url = article.get("url", "")

            # append to lists

            article_titles.append(title)
            article_images.append(image)
            article_descriptions.append(description)
            article_urls.append(url)
            
        # zip data
        data = zip(article_titles, article_images, article_descriptions, article_urls)
        return data
    
    else:
        return None
    

def fetch_categories(category_name):
    """
    Fetch news data for a specified category in the US dynamically using "top-headlines" endpoint.

    Parameters:
    - category_name (str): The name of the category.

    Returns:
    - zip: A zipped collection of article titles, images, descriptions, and URLs.
    - None: In case the request is unsuccessful.
    """

    params = {
        "country":"us",
        "category":category_name,
        "pageSize":50
    }
    return fetch_data("top-headlines", params)


def fetch_top_headlines():
    """
    Fetch top headlines for the US using "top-headlines" endpoint.

    Returns:
    - zip: A zipped collection of article titles, images, descriptions, and URLs.
    - None: In case the request is unsuccessful.
    """

    params = {
        "country":"us",
        "pageSize":50

    }
    return fetch_data("top-headlines", params)


def fetch_all_news(query):
    """
    Fetch global popular news using everything endpoint related to the query "news" and sorts them by popularity.

    Parameters:
    - query (str): The search query.

    Returns:
    - zip: A zipped collection of article titles, images, descriptions, and URLs.
    - None: In case the request is unsuccessful.
    """
        
    params = {
        "q":query,
        "sortBy":"popularity", 
        "language":"en",
        "pageSize":50
    }
    return fetch_data("everything", params)


def fetch_search_results(user_query):
    """
    Implements search queries through user input, sorts by relevancy using everything endpoint.

    Parameters:
    - user_query (str): The user's search query.

    Returns:
    - zip: A zipped collection of article titles, images, descriptions, and URLs.
    - None: In case the request is unsuccessful.
    """

    params = {
        "q":user_query,
        "sortBy":"relevancy",
        "language":"en",
        "pageSize":51
    }
    return fetch_data("everything", params)







    
