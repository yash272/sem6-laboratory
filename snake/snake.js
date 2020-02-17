const cvs = document.getElementById("snake");
const ctx = cvs.getContext("2d");
const box = 32;
const change = 5;
const ground = new Image();
ground.src = "img/ground.png";

const foodImg = new Image();
foodImg.src = "img/food.png";

let snake = [];
let flag = true;

snake[0] = {
    x: 9 * box,
    y: 15 * box
};

let initpos = {
    x: 9 * box,
    y: 15 * box
};
let food = {
    x: Math.floor(Math.random() * 17 + 1) * box,
    y: Math.floor(Math.random() * 15 + 3) * box
}

let plusx = [];
let plusy = [];
for (let i = 5; i < 14; i++) {
    plusx.push(i * box);
    plusy.push(9 * box);
}
for (let i = 6; i < 13; i++) {
    plusy.push(i * box);
    plusx.push(9 * box);
}



let score = 0;
let d;

document.addEventListener("keydown", direction);

function direction(event) {
    let key = event.keyCode;
    if (key == 37 && d != "RIGHT") {
        d = "LEFT";
    } else if (key == 38 && d != "DOWN") {
        d = "UP";
    } else if (key == 39 && d != "LEFT") {
        d = "RIGHT";
    } else if (key == 40 && d != "UP") {
        d = "DOWN";

    }
}

// cheack collision function
function collision(head, array) {
    for (let i = 0; i < array.length; i++) {
        if (head.x == array[i].x && head.y == array[i].y) {
            console.log("game over");
            return true;
        }
    }
    if (score >= change) {
        for (let i = 0; i < plusx.length; i++) {
            if (head.x == plusx[i] && head.y == plusy[i]) {
                return true;
            }

        }
    }
    return false;
}

const getval = function() {
        X = Math.floor(Math.random() * 17 + 1) * box;
        Y = Math.floor(Math.random() * 15 + 3) * box;
        for (i = 0; i < snake.length; i++) {
            if (snake[i].x == X && snake[i].y == Y)
                return getval();
        }
        for (i = 0; i < plusx.length; i++) {
            if (plusx[i] == X && plusy[i] == Y)
                return getval();
        }

        return { x: X, y: Y };
    }
    // draw everything to the canvas

function draw() {

    ctx.drawImage(ground, 0, 0);

    if (score >= change) {
        for (let i = 0; i < plusx.length; i++) {
            ctx.fillStyle = "black";
            ctx.fillRect(plusx[i], plusy[i], box, box);
        }
    }



    for (let i = 0; i < snake.length; i++) {
        ctx.fillStyle = (i == 0) ? "green" : "white";
        ctx.fillRect(snake[i].x, snake[i].y, box, box);

    }

    ctx.drawImage(foodImg, food.x, food.y);

    let snakeX = snake[0].x;
    let snakeY = snake[0].y;

    if (d == "LEFT") snakeX -= box;
    if (d == "UP") snakeY -= box;
    if (d == "RIGHT") snakeX += box;
    if (d == "DOWN") snakeY += box;

    // if the snake eats the food
    if (snakeX == food.x && snakeY == food.y) {
        score++;
        if (score == 1) {
            snake = [];
            snake[0] = initpos;
        }

        food = getval();
    } else {
        snake.pop();
    }


    let newHead = {
        x: snakeX,
        y: snakeY
    }

    if (snakeX < box || snakeX > 17 * box || snakeY < 3 * box || snakeY > 17 * box || collision(newHead, snake)) {
        clearInterval(game);
        flag = false;
        document.getElementById('game-over').style.display = 'block';
        document.getElementById('score').innerHTML = score;
    }

    snake.unshift(newHead);

    ctx.fillStyle = "white";
    ctx.font = "45px Changa one";
    ctx.fillText(score, 2 * box, 1.6 * box);


}


let game = setInterval(draw, 100);