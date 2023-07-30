document.addEventListener('DOMContentLoaded', function() {
    const textElement = document.querySelector('.typing-text');
    const textToType = "Welcome to My Webpage!"; // Add your desired text here
    let charIndex = 0;

    function typeText() {
        if (charIndex < textToType.length) {
            textElement.textContent += textToType[charIndex];
            charIndex++;
            setTimeout(typeText, 100); // Adjust the typing speed by changing the delay here
        }
    }

    // Start the typing animation
    typeText();
});