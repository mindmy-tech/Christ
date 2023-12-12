

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <!-- <img src="PXL_20230909_042504135.PORTRAIT.jpg" alt="" usemap="#vachan">
    <map name="#vachan" >
        <area shape="rect" coords="600, 1050, 750, 1200" href="im_the_eyes.html" alt="">
        <area shape="rect" coords="555, 915, 985, 1400" href="img_file.html" alt="">
    </map> -->
    <?php 
    echo "YO im Sabari!"
    ?>
    <form onsubmit="formSubmited()">
        Name : <input type="text">
        Age : <input type="number">

        <input type="submit" value="Submit">
    </form>
</body>
<script>
    function formSubmited() {
        alert("Die Now!")
    }

    document.querySelector('form').onsubmit = () => {
        alert("You have lived long");
    }
</script>
</html>