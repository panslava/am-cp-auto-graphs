import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MatchingsComponent } from './matchings.component';

describe('MatchingsComponent', () => {
  let component: MatchingsComponent;
  let fixture: ComponentFixture<MatchingsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MatchingsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MatchingsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
