const initialboard = [
    "br", "bn", "bb", "bq", "bk", "bb", "bn", "br",
    "bp", "bp", "bp", "bp", "bp", "bp", "bp", "bp",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "",
    "wp", "wp", "wp", "wp", "wp", "wp", "wp", "wp",
    "wr", "wn", "wb", "wq", "wk", "wb", "wn", "wr",
]

const container = document.getElementsByClassName("container")[0];
function create(html) {
    var frag = document.createDocumentFragment(),
        temp = document.createElement('div');
    temp.innerHTML = html;
    while (temp.firstChild) {
        frag.appendChild(temp.firstChild);
    }
    return frag;
}

for(let i = 1; i <= 64; i++) {
    var fragment = create(`<div>${i}</div>`);
    container.appendChild(fragment);
}