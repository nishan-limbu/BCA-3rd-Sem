<?php
include 'connect.php'; //including file that contains the connection to the database

if(isset($_POST['add']))
{
  $name_of_task = $_POST['name_of_task'];
  $due_date = $_POST['due_date'];
  $status = $_POST['status'];

  $sql = "INSERT INTO `mytask_crud` (name_of_tasks, due_date, status) VALUES ('$name_of_task', '$due_date', '$status')";

  $result = mysqli_query($con, $sql);
  if($result)
  {
    header('location:display.php');
  }
  else{
    die(mysqli_error($conn));
  }
}
?>

<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css">

    <title>Add Tasks</title>
  </head>
  <body>
    <div class="container my-5">
      <form method="post">
        <div class="form-group">
          <label for="name_of_task">Name of Task</label>
          <input type="text" class="form-control" id="name_of_task" placeholder="Enter name of task" autocomplete="off" name="name_of_task">
          <!-- <small id="emailHelp" class="form-text text-muted">We'll never share your email with anyone else.</small> -->
        </div>
        <div class="form-group">
          <label for="due_date">Due Date</label>
          <input type="date" class="form-control" id="due_date" placeholder="dd/mm/yyyy" name="due_date">
        </div>
        <div class="form-group">
          <label for="status">Status</label>
          <!-- <select name="status" id="status">
            <option value="started">Started</option>
            <option value="not_started">Not Started</option>
            <option value="in_progress">In Progress</option>
            <option value="completed">Completed</option>
          </select> -->
          <input type="text" class="form-control" id="status" placeholder="choice fields" name="status">
        </div>
        <button type="submit" class="btn btn-primary" name="add">Add Task</button>
      </form>
    </div>
  </body>
</html>