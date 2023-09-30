# ArticleHub

## A web application written in Python with Django backend and html, css and javascript for frontend. It uses NEWSAPI to get information about news articles and displays the article titles, images, descriptions, and url's to the user.

## [Watch the Video Demo](https://vimeo.com/869726456)

## Features:

### Global Popular News: 
- Fetches and displays popular news articles from around the world.
- Utilizes the `fetch_all_news` function in `helpers.py` with parameters set to sort   articles by popularity and language (English).
- Retrieves up to 50 articles using the 'everything' endpoint.

### US Top Headlines:
- Fetches and displays top headlines from the United States.
- Uses the `fetch_top_headlines` function in `helpers.py` with the 'country' parameter set to 'US.'
- Retrieves up to 50 articles using the 'top-headlines' endpoint.

### US Category Based:
- Fetches and displays category-based news from the United States.
- Uses the `fetch_categories` function in `helpers.py` with dynamic category selection.
- Retrieves up to 50 articles using the 'top-headlines' endpoint.

### A Custom Search Bar:
- Exclusive to registered users, the custom search bar allows users to search for all types of articles.
- Available in the navbar after user registration and login.
- Utilizes the `fetch_search_results` function in `helpers.py` to retrieve up to 50 articles based on user queries, sorted by relevancy and language (English).
- Uses the 'everything' endpoint.

### User Registration:
- Handles user registration using Django forms.
- Utilizes the `RegisterForm` form, inheriting from `UserCreationForm`.
- Registration, login, and logout functionalities are implemented using functions defined in `views.py`.

### User Log in and Log out:
- Utilizes Django's `authenticate` and `login` functions for user authentication.
- Displays error messages using the 'messages' framework for validation.
- Redirects authenticated users to their profile page upon login.
- Users see a welcome message with their username upon login.
- The user profile page is protected using the `login_required` decorator.
- Provides access to the custom search bar upon login.
- Logs users out and redirects them to the login page upon logout.

## Directory:

- `apps.py`: Configures the app name as `news_app`.
- `forms.py`: Defines the `RegisterForm` class for user registration.
- `helpers.py`: Contains error handling functions and API-related configurations and functions.
- `urls.py`: Defines URL patterns for view functions.

### Views:

- `register`: Handles user registration form submission. If valid, a new user account is created, and the user is logged in. Displays validation errors if any.
- `login_view`: Handles user login form submission. If valid credentials are provided, the user is logged in and redirected to their profile page. Displays an error message for invalid credentials.
- `logout_view`: Logs out the authenticated user and redirects them to the login page.
- `user_profile`: Displays the user's profile information if authenticated.
- `index`: Renders the homepage.
- `categories`: Renders news articles for a specific category. Displays an error message in case of an API error.
- `top_headlines`: Renders top headlines for the US. Displays an error message in case of an API error.
- `all_news`: Renders global popular news based on the query "news." Displays an error message in case of an API error.
- `search_results`: Renders search results based on user input. Handles various scenarios, including API errors, empty user queries, and no search results.

### Models:

- `models.py`: Defines the `UserProfile` model, extending the built-in `User` model with additional user-specific information.

### Templates:

- `templates`: Contains HTML templates organized into subdirectories for different parts of the application, and as well as the `Javascript` script which is contained within the layout template.

### Static Files:

- `static`: Contains static files like CSS and images.
  - `css`: Stylesheets for the application.
  - `images`: Image assets.

### Management Commands:

- management dir contains a nested sub-dir(commands) which contains the myscript.py file.
- `management`: Contains custom management commands.
  - `commands`: Contains the `myscript.py` file.

## Custom Management Command: `myscript`

- This command is intended for checking the API's response status and is not expected to have any other significant functionality. It can be useful for debugging and ensuring that the API is accessible and responding as expected.
- A successful response would have a status code of `200 OK`.
- An unsuccessful response will have a status code different from 200 OK such as `500 Internal Server Error`. This probably suggests there are issues with the API for example a problem with the configuration or API could be down.

### Usage:

To execute this custom command, run the following command in your terminal:

```shell
python manage.py myscript

Using the Application:

1. Open the application by running the server in the terminal using python manage.py runserver.
2. Open the browser and click on news_app, and the application will open.
3. You will be able to see all the features of the app on the homepage.
4. Click on your desired feature on the navbar. 
- For "US" related news: Navigate to "Top Headlines" or "Categories".
- For "Global" news: Navigate to "Popular".
- For "Custom" global search: You need to first register and login. See instructions below

Optional:
Registering for an Account:

5. Navigate to the "REGISTER" button on the navbar and fill in the required information, including your desired username and password.
6. Once successful, login with the same username and password. 
7. A "PROFILE" will be successfully created for you, and the custom search bar in the navbar will appear.

Using the custom search bar:

- To use the custom search bar simply type in your news related query to view articles.

Logging Out

- To log out, click on the "LOGOUT" link in the navigation bar.
- Once logged out, the custom search bar will become unavailable.

Logging In

1. Click on the "LOGIN" link in the navigation bar.
2. Enter your username and password.
3. Click the "LOGIN" button.



