const h2 = document.querySelector('.typing-effect');
const text = "Am i Good enough  ?"; 
const delay = 200; 

function typeEffect() {
  h2.textContent = text.substring(0, h2.textContent.length + 1);
  if (h2.textContent === text) {
    setTimeout(() => {
      h2.textContent = ""; 
      setTimeout(typeEffect, 400); 
    }, 800);
  } else {
    setTimeout(typeEffect, delay);
  }
}

typeEffect();
