const url = 'process.php';
const form = document.querySelector('form');
var loading = false;

var idiv = document.getElementById("inputform");
var fdiv = document.getElementById("uploadform");

function validate(){
	$.ajax({
		type:     "post",
		data:     {functionname: 'add', arguments: [document.getElementById("code").value, document.getElementById("email").value]},
		cache:    false,
		url:      "validate.php",
		dataType: "application/json",
		error: function (request, error) {
			console.log(arguments);
			alert(" Can't do because: " + error);
		},
		success: function (request) {
			if(request.checked)
				window.open("ibleibdahoam.ddns.net/upload/custom.hmtl","_self")
		}
	});
}


/*function validate(){
	jQuery.ajax({
		type: "POST",
		url: 'validate.php',
		dataType: 'json',
		data: {functionname: 'add', arguments: [document.getElementById("code").value, document.getElementById("email").value]},
	
		success: function (data) {
			if(data.checked){	
				idiv.style.display="none";
				fdiv.style.display="inline";
			} else {
				alert("Der Code passt nicht zu deiner E-Mail.")
			}
		}
	});
}*/



$(document).ready(function(){
	$('#uploadImage').submit(function(event){
	 if($('#uploadFile').val())
	 {
	  event.preventDefault();
	  $('#loader-icon').show();
	  $('#targetLayer').hide();
	  $(this).ajaxSubmit({
	   target: '#targetLayer',
	   beforeSubmit:function(){
		$('.progress-bar').width('50%');
	   },
	   uploadProgress: function(event, position, total, percentageComplete)
	   {
		$('.progress-bar').animate({
		 width: percentageComplete + '%'
		}, {
		 duration: 1000
		});
	   },
	   success:function(){
		//DB write upload finished, tokenused = 1;
		$('#loader-icon').hide();
		$('#targetLayer').show();
		$('#uploadform').hide();
		$('#thanks').show();

	   },
	   resetForm: true
	  });
	 }
	 return false;
	});
 });