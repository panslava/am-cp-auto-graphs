import { Component, OnInit } from '@angular/core';
import {FormBuilder, FormGroup, Validators} from '@angular/forms';
import {SendDataService} from '../send-data.service';

@Component({
  selector: 'app-mincut',
  templateUrl: './mincut.component.html',
  styleUrls: ['./mincut.component.css']
})
export class MincutComponent implements OnInit {

  private task: FormGroup;
  isLoad = false;
  res;

  constructor(private fb: FormBuilder, private sendDataService: SendDataService) { }

  ngOnInit() {
    this.task = this.fb.group({
      task: ['', [Validators.required]]
    });

  }

  sendData() {
    this.sendDataService.mincut(this.task.value.task).subscribe(res => {
      this.isLoad = true;
      this.res = res.answer;
      this.task.reset();
    });
  }
}
