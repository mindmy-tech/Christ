const h2 = document.querySelector('.typing-effect');
const text = "Hello world !"; // Replace with your desired text
const delay = 200; // Delay between each letter in milliseconds

function typeEffect() {
  h2.textContent = text.substring(0, h2.textContent.length + 1);
  if (h2.textContent === text) {
    setTimeout(() => {
      h2.textContent = ""; // Clear the text
      setTimeout(typeEffect, 400); // Delay before starting again
    }, 800); // Wait for 2 seconds before clearing the text
  } else {
    setTimeout(typeEffect, delay);
  }
}

typeEffect();
