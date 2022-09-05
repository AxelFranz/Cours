$(document).ready(function(){
	$(".callback").click(function() {
		var disp = $(".disparaitre");
		disp.fadeOut(1000,function(){
			disp.text("NON")
		}).fadeIn(1000);
	});
});