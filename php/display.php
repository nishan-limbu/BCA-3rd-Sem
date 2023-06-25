<?php
  include 'connect.php'; //including the file that connects to the database
?>

<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  
  <!-- External CSS -->
  <link rel="stylesheet" href="css/display.css">

  <!-- Bootstrap CSS -->
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css">
  
  <title>My Tasks</title>
</head>
<body>
  <div class="container my-5">
    <h1>My Tasks</h1>
    <!-- button for adding tasks -->
    <button type="submit" class="btn btn-info" name="add" id="button_add">
      <a href="add_tasks.php" id="add_task">Add Tasks</a>  
    </button>

    <!-- Search bar to search different tasks names -->
    <div class="form-group">
      <input type="text" class="form-control" id="searchInput" placeholder="Search tasks" oninput="searchTasks()">
    </div>

    <!-- Table that displays all the tasks with different fields on it. -->
    <table class="table my-3" id="myTable">
      <thead class="thead-dark">
        <tr>
          <th scope="col">S.N</th>
          <th scope="col">Name of Tasks</th>
          <th scope="col">Due Date</th>
          <th scope="col">Status</th>
          <th scope="col">Operations</th>
        </tr>
      </thead>
      <tbody>
        <!-- fetching all the data from the database and displaying on the table -->
        <?php
        $sql = "SELECT * FROM mytask_crud ";
        $result = mysqli_query($con, $sql);

        if($result){
          while($row=mysqli_fetch_assoc($result)){
            $id = $row['id'];
            $name_of_task = $row['name_of_tasks'];
            $due_date = $row['due_date'];
            $status = $row['status'];
            echo '<tr>
            <td>'.$id.'</td>
            <td>'.$name_of_task.'</td>
            <td>'.$due_date.'</td>
            <td>'.$status.'</td>
            <td>
              <button type="submit" class="btn btn-info" name="update" style="width: 47%;">
                <a href="update.php?update_id='.$id.'" class="text-white">Update</a>  
              </button>

              <button type="submit" class="btn btn-danger" name="delete" style="width: 47%;margin-left: 7px;">
                <a href="delete.php?delete_id='.$id.'" class="text-white">Delete</a>  
              </button>
            </td>
          </tr>';
          }
        }
        ?>
        
      </tbody>
    </table>

  </div>
  <script>
    function searchTasks() {
      var input, filter, table, tr, td, i, txtValue;
      input = document.getElementById("searchInput");
      filter = input.value.toUpperCase();
      table = document.querySelector(".table");
      tr = table.getElementsByTagName("tr");

      // Loop through all table rows and hide those that don't match the search query
      for (i = 0; i < tr.length; i++) {
        td = tr[i].getElementsByTagName("td")[1]; // Assuming the name of tasks is in the second column (index 1)
        if (td) {
          txtValue = td.textContent || td.innerText;
          if (txtValue.toUpperCase().indexOf(filter) > -1) {
            tr[i].style.display = "";
          } else {
            tr[i].style.display = "none";
          }
        }
      }
    }
  </script>

</body>
</html>