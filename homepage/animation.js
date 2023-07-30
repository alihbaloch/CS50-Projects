document.addEventListener('DOMContentLoaded', function() {
    const textElement = document.querySelector('.typing-text');
    const textToType = "Hello and Welcome Aboard! Explore My Journey.";
    let charIndex = 0;

    function typeText() {
        if (charIndex < textToType.length) {
            textElement.textContent += textToType[charIndex];
            charIndex++;
            setTimeout(typeText, 70);
        }
    }
    typeText();
});