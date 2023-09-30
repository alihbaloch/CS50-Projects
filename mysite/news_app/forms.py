from typing import Any
from django import forms
from django.contrib.auth.forms import UserCreationForm 
from django.contrib.auth.models import User  

class RegisterForm(UserCreationForm):

    """
    A custom RegistrationForm based on Django's UserCreationForm.

    This form extends the UserCreationForm to customize the appearance of the form
    and add custom CSS classes to input fields.

    Attributes:
        username: A field for entering the username.
        password1: A field for entering the password.
        password2: A field for confirming the password.

    Note:
        This form inherits fields and validation logic from UserCreationForm and adds
        Bootstrap CSS classes for styling.
    """
    
    class Meta:
        model = User
        fields = ('username', 'password1', 'password2')


    def __init__(self, *args: Any, **kwargs: Any) -> None:
        """
        Initialize the RegisterForm.

        Args:
            args: Additional positional arguments.
            kwargs: Additional keyword arguments.
        """
        super(RegisterForm, self).__init__(*args, **kwargs)

        # Add Bootstrap CSS classes ('form-control') to form fields to override default form styling
        self.fields['username'].widget.attrs['class'] = 'form-control'
        self.fields['password1'].widget.attrs['class'] = 'form-control'
        self.fields['password2'].widget.attrs['class'] = 'form-control'
