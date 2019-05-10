import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MincostMaxflowComponent } from './mincost-maxflow.component';

describe('MincostMaxflowComponent', () => {
  let component: MincostMaxflowComponent;
  let fixture: ComponentFixture<MincostMaxflowComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MincostMaxflowComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MincostMaxflowComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
