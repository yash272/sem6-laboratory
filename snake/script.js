const cvs = document.getElementById("snake");
const ctx = cvs.getContext("2d");
const box = 48;
var seed = Math.random() * 1000 + 1;

function random() {
    var x = Math.sin(seed++) * 10000;
    return x - Math.floor(x);
}

const ground = new Image();
ground.src = "ground.png";

const foodImg = new Image();
foodImg.src = "food.png";
// const upImg = new Image();
// upImg.src = "up.png";
// const leftImg = new Image();
// leftImg.src = "left.png";
// const rightImg = new Image();
// rightImg.src = "right.png";
// const downImg = new Image();
// downImg.src = "down.png";

const pupImg = new Image();
pupImg.src = "pup.png";
const pleftImg = new Image();
pleftImg.src = "pleft.png";
const prightImg = new Image();
prightImg.src = "pright.png";
const pdownImg = new Image();
pdownImg.src = "pdown.png";

let snake = [];
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
console.log(plusx,plusy);
snake[0] = {
    x: 9 * box,
    y: 10 * box
};
let food = {
    x: Math.floor(random() * 17 + 1) * box,
    y: Math.floor(random() * 15 + 3) * box
};
let score = 0;
let d = "RIGHT";

document.addEventListener("keydown", direction);

function direction(event) {
    if (event.keyCode == 37 && d != "RIGHT") {
        d = "LEFT";
    } else if (event.keyCode == 38 && d != "DOWN") {
        d = "UP";
    } else if (event.keyCode == 39 && d != "LEFT") {
        d = "RIGHT";
    } else if (event.keyCode == 40 && d != "UP") {
        d = "DOWN";
    }
}

function collision(head, array) {
    for (let i = 0; i < array.length; i++) {
        if (head.x == array[i].x && head.y == array[i].y) {
            return true;
        }
    }
    if (score >= 5) {
        for (let i = 0; i < plusx.length; i++) {
            if (head.x == plusx[i] && head.y == plusy[i]) {
                return true;
            }
        }
    }
    return false;
}

function draw() {
    ctx.drawImage(ground, 0, 0, 912, 912);
    // ctx.drawImage(upImg, 1012, 0, 100, 100);
    // ctx.drawImage(downImg, 1012, 100, 100, 100);
    // ctx.drawImage(leftImg, 912, 100, 100, 100);
    // ctx.drawImage(rightImg, 1112, 100, 100, 100);
    if (score >= 5) {
        for (let i = 0; i < plusx.length; i++) {
            ctx.fillStyle = "black";
            ctx.fillRect(plusx[i], plusy[i], box, box);
        }
    }
    for (let i = 0; i < snake.length; i++) {
        ctx.fillStyle = i == 0 ? "red" : "green";
        ctx.fillRect(snake[i].x, snake[i].y, box, box);

        ctx.strokesStyle = "blue";
        ctx.strokeRect(snake[i].x, snake[i].y, box, box);
    }
    ctx.drawImage(foodImg, food.x, food.y);
    ctx.fillStyle = "white";
    ctx.font = "45px Changa one";
    ctx.fillText(score * 10, 2 * box, 1.6 * box);

    let snakeX = snake[0].x;
    let snakeY = snake[0].y;
    if (d == "LEFT") {
        snakeX -= box;
        // ctx.drawImage(pleftImg, 912, 100, 100, 100);
    }
    if (d == "UP") {
        snakeY -= box;
        // ctx.drawImage(pupImg, 1012, 0, 100, 100);
    }
    if (d == "RIGHT") {
        snakeX += box;
        // ctx.drawImage(prightImg, 1112, 100, 100, 100);
    }
    if (d == "DOWN") {
        snakeY += box;
        // ctx.drawImage(downImg, 1012, 100, 100, 100);
    }
    let newHead = {
        x: snakeX,
        y: snakeY
    };
    if (
        snakeX < box ||
        snakeX > 17 * box ||
        snakeY < 3 * box ||
        snakeY > 17 * box ||
        collision(newHead, snake)
    ) {
        clearInterval(game);
    }

    snake.unshift(newHead);
    if (snakeX == food.x && snakeY == food.y) {
        score++;
        food.x = Math.floor(random() * 17 + 1) * box;
        food.y = Math.floor(random() * 15 + 3) * box;
    } else {
        snake.pop();
    }
}

let game = setInterval(draw, 150);