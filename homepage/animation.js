


document.addEventListener('DOMContentLoaded', function() {
    const box = document.querySelector('.box');

    function moveBox() {
        const randomX = Math.random() * (window.innerWidth - box.offsetWidth);
        const randomY = Math.random() * (window.innerHeight - box.offsetHeight);
        box.style.transform = `translate(${randomX}px, ${randomY}px)`;
    }

    // Move the box every 3 seconds
    setInterval(moveBox, 3000);
});