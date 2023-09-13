const leftEye = document.getElementById('left-eye');
const rightEye = document.getElementById('right-eye');

document.addEventListener('mousemove', (e) => {
    const characterX = document.querySelector('.character').getBoundingClientRect().left;
    const characterY = document.querySelector('.character').getBoundingClientRect().top;
    
    const mouseX = e.clientX - characterX;
    const mouseY = e.clientY - characterY;

    const angle = Math.atan2(mouseY - 25, mouseX - 25);

    leftEye.style.transform = `rotate(${angle}rad)`;
    rightEye.style.transform = `rotate(${angle}rad)`;
});
