function updateText() {
    // Get the form input value
    var nameInput = document.getElementById("name");
    var name = nameInput.value;

    // Check if a name was entered
    if (name.trim() === "") {
        alert("Please enter your name.");
        return; // Don't update the text if no name is entered
    }

    // Update the text content
    var displayText = document.getElementById("displayText");
    displayText.textContent = "Hello, " + name + "!";
}
