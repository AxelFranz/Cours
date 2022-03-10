var notes = [10,15,6,14,14,13,19,10,17,9];
function f_afficher_tab(tab,tout)
{
	if(typeof(tout) == "boolean")
	{
		if(tout)
		{
			for(let i = 0;i < tab.length;i++)
			{
				document.writeln(tab[i]);
			}
		} else {
			for(let i = 0;i < tab.length;i++)
			{
				if(tab[i] >= 15)
				{
				document.writeln(tab[i]);
				}
			}

		}
	}
	else {alert("Erreur de type : utiliser un tableau et un booleen")}                                                                                                                                                                                                                                                                                                    
}

function w_afficher_tab(tab)
{
	let i = 0;
	while(i != tab.length)
	{
		document.writeln(tab[i]);
		i++;
	}
}

function conversion()
{
	var a_conv = document.getElementById("input").value;
	var unit_fin = document.getElementById("unite").value;
	if(unit_fin == "pouce")
	{
		a_conv = a_conv/2.54 + " pouces";
	}
	else if (unit_fin == "cm")
	{
		a_conv = a_conv*2.54 + " cm";	
	}
	else if (unit_fin == "lb")
	{
		a_conv = a_conv/454 + " lbs";
	}
	else if (unit_fin == "gramme")
	{
		a_conv = a_conv*454 + " grammes";
	}
	else{alert("Erreur");}
	var paragraphe = document.getElementById("final");
	paragraphe.innerHTML += a_conv;
}
