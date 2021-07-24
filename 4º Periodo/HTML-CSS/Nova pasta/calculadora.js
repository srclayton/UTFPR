function digitado(e) {
	let tecla=e.target.innerText;
	let visor=document.getElementById('visor');
	switch (tecla) {
		case	'C' : visor.innerHTML = "0,"; return;
	}
	visor.innerHTML += tecla;
	
}

window.onload = function() {
	var buttons = document.querySelectorAll('button');
	for (var i = 0; i < buttons.length; i++) {
		buttons[i].addEventListener("click", digitado);
	}
}
