let randomNum, guessCounter, guessCount;

let hint = document.getElementById("hint");
let status = document.getElementById("guessStatus");
let prev = document.getElementById("prevGuesses");
let resetBtn = document.getElementById("resetBtn");
let submitBtn = document.getElementById("submitguess");

function initialize() {
    submitBtn.disabled = false;
    randomNum = Math.floor(Math.random() * 10 + 1);
    guessCounter = 0;
    guessCount = 10;
    resetBtn.style.display = "none";
    prev.textContent = "Previous Guesses: ";
    hint.textContent = "";
    status.textContent = "";
    document.getElementById("guessedNum").value = "";
    document.getElementById("guessDisplay").textContent = "Guesses: " + guessCounter;
}

initialize();

resetBtn.onclick = function() {
    initialize();
}

submitBtn.onclick = function() {
    let num = Number(document.getElementById("guessedNum").value);
    prev.textContent += num + " ";

    guessCounter++;
    document.getElementById("guessDisplay").textContent = "Guesses: " + guessCounter;

    if (num === randomNum) {
        submitBtn.disabled = true;
        status.textContent = "You've got it right!";
        hint.textContent = "";
        resetBtn.style.display = "block";
    } else if (guessCount > 0) {
        guessCount--;
        if (guessCount === 0) {
            submitBtn.disabled = true;
            status.textContent = "You lost!"
            resetBtn.style.display = "block";
        }
        else if (num > randomNum) {
            hint.textContent = "Please try a smaller number.";
            status.textContent = "Wrong";
        } else {
            hint.textContent = "Please try a larger number.";
            status.textContent = "Wrong";
        }
        
    }
}

